import mido, sys
from mido import MidiFile
from mido import MidiTrack
from mido import Message

mid = MidiFile("kirby-sand-canyon.mid")

with open("output.txt", "w") as f:
    for i, track in enumerate(mid.tracks):
        
        newMid = MidiFile()
        newTrack = MidiTrack()

        output = []

        for msg in track:
            if not msg.is_meta:
                time = msg.time
                if (msg.time >= 256):
                    # pad out spaces longer than 511 time units
                    while time >= 256:
                        time -= 256
                        output.append(bin(0b1111111100000000))
                if msg.type == "note_on" and msg.velocity != 0:
                    output.append(bin((time << 8) | 0b10000000 | msg.note))
                    newTrack.append(Message("note_on", note = msg.note, time = msg.time))
                elif msg.type == "note_off" or (msg.type == "note_on" and msg.velocity == 0):
                    output.append(bin((time << 8) | 0b00000000 | msg.note))
                    newTrack.append(Message("note_off", note = msg.note, time = msg.time))
                else:
                    output.append(bin((time << 8) | 0b00000000))

                
                
        f.write("//Track {} : {}\n".format(i, track.name))
        f.write("static const uint16_t Track{}[] PROGMEM {{".format(i) + ", ".join(output) + "};\n")



        tempTime = 0

        lastnote = 0

        if (i == 1):
            newTrack1 = MidiTrack()
            newMid.tracks.append(newTrack)
            newMid.tracks.append(newTrack1)

            for m in output:
                parsed = int(m, 2)
                
                tempTime += parsed >> 8

                if (parsed & 0b0000000011111111) == 0b0000000000000000:
                    #empty
                    continue
                
                elif (parsed & 0b0000000010000000) == 0b0000000000000000:
                    #note off
                    note = parsed & 0b0000000001111111
                    newTrack1.append(Message("note_off", note = note, time = tempTime))
                    tempTime = 0
                else:
                    #note on
                    note = parsed & 0b0000000001111111
                    newTrack1.append(Message("note_on", velocity = 64, note = note, time = tempTime))
                    tempTime = 0

            newMid.save("output.mid")

    
# ttttttttnnnnnnnn
# t = time in MIDI units since last message (0 - 255 time units)
# n = MIDI note number (21 - 127 or 0b0010101 - 0b1111111) + on or off

# note 0b00000000 = empty message
# note 0b1xxxxxxx = on
# note 0b0xxxxxxx = off