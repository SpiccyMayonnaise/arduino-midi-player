import mido, sys
from mido import MidiFile

mid = MidiFile("core 8-bit.mid")

for i, track in enumerate(mid.tracks):
    print('Track {}: {}'.format(i, track.name))

    for msg in track:
        if not msg.is_meta:
            if msg.type == "note_on":
                print("{}: {} (note {}, {})".format(track.name, msg.type, format(msg.note, "07b"), msg.time))
            
# tttttttttnnnnnnn
# t = time in MIDI units since last message
# n = MIDI note number (21 - 127 or 0b0010101 - 0b1111111)

# note 0b0000000 = note off