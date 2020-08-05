import mido, sys
from mido import MidiFile

mid = MidiFile("core 8-bit.mid")

with open("output.txt", "w") as f:
    for i, track in enumerate(mid.tracks):
        print('Track {}: {}'.format(i, track.name))
        
        output = []

        for msg in track:
            if not msg.is_meta:
                time = msg.time
                if (msg.time >= 512):
                    # pad out spaces longer than 511 time units
                    while time >= 512:
                        time -= 512
                        output.append(bin(0b1111111110000000))
                if msg.type == "note_on":
                    output.append(bin((time << 7) | msg.note))
                elif msg.type == "note_off":
                    output.append(bin((time << 7) | 0b0000001))
                else:
                    output.append(bin((time << 7) | 0b0000000))
        f.write("//Track {} - {}\n".format(i, track.name))
        f.write("static const uint16_t Track{}[] PROGMEM {{".format(i) + ", ".join(output) + "};\n")
        # f.write("static const uint16_t Track{}_Length = sizeof( Track{} ) / sizeof(uint16_t); \n".format(i, i))
        print(", ".join(output))
    
# tttttttttnnnnnnn
# t = time in MIDI units since last message (0 - 511 time units)
# n = MIDI note number (21 - 127 or 0b0010101 - 0b1111111)

# note 0b0000000 = empty message
# note 0b0000001 = note off