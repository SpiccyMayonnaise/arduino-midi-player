#include "Tone.h"

class Voice {
    private:
      uint16_t pin;

      //The current index of the note
      uint64_t currentNote = 1;
      //The time of the next note      
      long double nextNoteTime = 0;

      bool useArpeggio = false;

      uint8_t currentArpeggio = 0;

      long double nextArpeggioTime = 0;

      //The current MIDI notes to be arpeggiated
      uint8_t notes[8];
      uint8_t numNotes = 0;

      const uint16_t* trackStart;
      uint64_t trackLength;

      uint8_t nextAction = 0;

      uint16_t ticksPerBeat;

      long double tempo;

      long double arpeggio;

      Tone tone;
    
    public:
      Voice(int pin, const uint16_t* trackStart, uint64_t trackLength, long double tempo, long double arpeggio, bool useArpeggio) {
        this->pin = pin;

        tone.begin(pin);

        Serial.println(pin);

        this->trackStart = trackStart;
        this->trackLength = trackLength;
        this->useArpeggio = useArpeggio;
        this->arpeggio = arpeggio;
        this->tempo = tempo;
        this->ticksPerBeat = *trackStart;
      }

      void Update(uint64_t currentTime) {
        if (currentNote < trackLength) {
          while (nextNoteTime < (long double)currentTime) {
            if (nextAction == 0b00000000) {
              // Do nothing
            } else if (nextAction >> 7 == 0) {
              // Note off
              uint8_t note = (nextAction & 0b0000000001111111);
              
              if (numNotes != 0) {
                RemoveNoteAt(GetIndexOfNote(note));
                numNotes--;
              }
            } else {
              // Note on
              uint8_t note = (nextAction & 0b0000000001111111);
              
              if (numNotes == 8) {
                notes[7] = note;
              } else {
                notes[numNotes] = note;
                numNotes++;
              }

            }

            uint16_t data = pgm_read_word((uint16_t *)(trackStart + currentNote));

            nextAction = data;
            
            ///Duration of the note in ticks
            long double Duration = (long double)(data >> 8);
            

            currentNote++;
            
            nextNoteTime += ((Duration / (long double)ticksPerBeat) / (tempo / 60)) * 1000000;
          }
          if (numNotes == 0) {
            tone.stop();
          } else {
            if (useArpeggio) {
              if (nextArpeggioTime < (long double)currentTime) {
                nextArpeggioTime = (long double)currentTime + (tempo / arpeggio) * 1000000;
                currentArpeggio++;
                currentArpeggio %= numNotes;
              }

              tone.play(NoteToFrequency(notes[currentArpeggio]));
            } else {
              tone.play(NoteToFrequency(notes[numNotes - 1]));
            }
          }
        } else {
          // Song ended
          tone.stop();
        }
      }

      uint16_t NoteToFrequency(uint8_t note) {
            static const uint16_t Freq8[] = { 4186 , 4435 , 4699  , 4978 , 5274 , 5588 , 5920 , 6272 , 6645 , 7040 , 7459 , 7902 };
            return Freq8[note % 12] / ( 1 << (8-(note / 12)) );
      }

      uint8_t GetIndexOfNote(uint8_t note) {
        for (uint8_t i = 0; i < 8; i++)
        {
          if (notes[i] == note) {
            return note;
          }
        }

        //Note wasn't found
        return 8;
      }

      void RemoveNoteAt(uint8_t index) {
        if (index >= 8) {
          return;
        }

        uint8_t i = index;
        while (++i < 8) {
          notes[i - 1] = notes [i];
        }
        
      }
};