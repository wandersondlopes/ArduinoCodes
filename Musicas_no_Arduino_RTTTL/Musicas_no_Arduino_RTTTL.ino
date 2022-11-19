/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

A fun sketch to demonstrate the use of the Tone library.

To mix the output of the signals to output to a small speaker (i.e. 8 Ohms or higher),
simply use 1K Ohm resistors from each output pin and tie them together at the speaker.
Don't forget to connect the other side of the speaker to ground!

You can get more RTTTL (RingTone Text Transfer Language) songs from
http://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation

criado   2017
por 
modificado nov 2022
por Wanderson D. Lopes
*/



#include <Tone.h>

Tone tone1;

#define OCTAVE_OFFSET 0

int notes[] = { 0,
NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};

//char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
//char *song = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";
char *song1 = "TakeOnMe:d=4,o=4,b=160:8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";
//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
//char *song = "Muppets:d=4,o=5,b=250:c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,8a,8p,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,8e,8p,8e,g,2p,c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,a,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,d,8d,c";
//char *song = "Xfiles:d=4,o=5,b=125:e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,g6,f#6,e6,d6,e6,2b.,1p,g6,f#6,e6,d6,f#6,2b.,1p,e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,e6,2b.";
//char *song = "Looney:d=4,o=5,b=140:32p,c6,8f6,8e6,8d6,8c6,a.,8c6,8f6,8e6,8d6,8d#6,e.6,8e6,8e6,8c6,8d6,8c6,8e6,8c6,8d6,8a,8c6,8g,8a#,8a,8f";
//char *song = "20thCenFox:d=16,o=5,b=140:b,8p,b,b,2b,p,c6,32p,b,32p,c6,32p,b,32p,c6,32p,b,8p,b,b,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,g#,32p,a,32p,b,8p,b,b,2b,4p,8e,8g#,8b,1c#6,8f#,8a,8c#6,1e6,8a,8c#6,8e6,1e6,8b,8g#,8a,2b";
//char *song = "Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6";
//char *song = "MASH:d=8,o=5,b=140:4a,4g,f#,g,p,f#,p,g,p,f#,p,2e.,p,f#,e,4f#,e,f#,p,e,p,4d.,p,f#,4e,d,e,p,d,p,e,p,d,p,2c#.,p,d,c#,4d,c#,d,p,e,p,4f#,p,a,p,4b,a,b,p,a,p,b,p,2a.,4p,a,b,a,4b,a,b,p,2a.,a,4f#,a,b,p,d6,p,4e.6,d6,b,p,a,p,2b";
//char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
//char *song = "GoodBad:d=4,o=5,b=56:32p,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,d#,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,c#6,32a#,32d#6,32a#,32d#6,8a#.,16f#.,32f.,32d#.,c#,32a#,32d#6,32a#,32d#6,8a#.,16g#.,d#";
//char *song = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#";
//char *song = "A-Team:d=8,o=5,b=125:4d#6,a#,2d#6,16p,g#,4a#,4d#.,p,16g,16a#,d#6,a#,f6,2d#6,16p,c#.6,16c6,16a#,g#.,2a#";
//char *song = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
//char *song = "Jeopardy:d=4,o=6,b=125:c,f,c,f5,c,f,2c,c,f,c,f,a.,8g,8f,8e,8d,8c#,c,f,c,f5,c,f,2c,f.,8d,c,a#5,a5,g5,f5,p,d#,g#,d#,g#5,d#,g#,2d#,d#,g#,d#,g#,c.7,8a#,8g#,8g,8f,8e,d#,g#,d#,g#5,d#,g#,2d#,g#.,8f,d#,c#,c,p,a#5,p,g#.5,d#,g#";
//char *song = "Gadget:d=16,o=5,b=50:32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,32d#,32f,32f#,32g#,a#,d#6,4d6,32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,8d#";
//char *song = "Smurfs:d=32,o=5,b=200:4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8f#,p,8a#,p,4g#,4p,g#,p,a#,p,b,p,c6,p,4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8b,p,8f,p,4f#";
//char *song = "MahnaMahna:d=16,o=6,b=125:c#,c.,b5,8a#.5,8f.,4g#,a#,g.,4d#,8p,c#,c.,b5,8a#.5,8f.,g#.,8a#.,4g,8p,c#,c.,b5,8a#.5,8f.,4g#,f,g.,8d#.,f,g.,8d#.,f,8g,8d#.,f,8g,d#,8c,a#5,8d#.,8d#.,4d#,8d#.";
//char *song = "LeisureSuit:d=16,o=6,b=56:f.5,f#.5,g.5,g#5,32a#5,f5,g#.5,a#.5,32f5,g#5,32a#5,g#5,8c#.,a#5,32c#,a5,a#.5,c#.,32a5,a#5,32c#,d#,8e,c#.,f.,f.,f.,f.,f,32e,d#,8d,a#.5,e,32f,e,32f,c#,d#.,c#";
//char *song = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
//char *song = "goldenaxe:d=4,o=5,b=112:8a4,32p,16b4,16p,2c,16p,8a4,32p,16b4,16p,2c,16p,8b4,32p,16c,16p,d,32p,8g.4,16c,16b4,2a4";
//char *song = "missathing:d=4,o=5,b=125:2p,16a,16p,16a,16p,8a.,16p,a,16g,16p,2g,16p,p,8p,16g,16p,16g,16p,16g,8g.,16p,c6,16a#,16p,a,8g,f,g,8d,8f.,16p,16f,16p,16c,8c,16p,a,8g,16f,16p,8f,16p,16c,16p,g,f";
//char *song = "batman:d=8,o=5,b=180:b,b,a#,a#,a,a,a#,a#,b,b,a#,a#,a,a,a#,a#,4b,p,4b";
//char *song = "Beethoven:d=4,o=5,b=160:c,e,c,g,c,c6,8b,8a,8g,8a,8g,8f,8e,8f,8e,8d,c,e,g,e,c6,g";
//char *song = "Coca-cola:d=4,o=5,b=125:8f#6,8f#6,8f#6,8f#6,g6,8f#6,e6,8e6,8a6,f#6,d6,2p";
//char *song = "Abba - Mamma Mia :d=4,o=5,b=40:32f6,32d#6,32f6,8d#6,32d#6,32d#6,32f6,32g6,32f6,16d#.6,32p,16f6,8d#6,16g#6,32g#6,32g#6,32g#6,16g6,16d#.6,32p,8a#6,32a#6,32a#6,16a#6,16f6,16g6,8g#6,16g6,16g6,32g6,16g6,16d6,16d#6,8f6,16f6,8d#6,16g#6,32g#6,32g#6,32g#6,32g6,32d#6,32f6,16d#6";
//char *song = "Alice Deejay - Better Off Alone : d=4,o=5,b=125:a,8a,f#,a,a,g#,8e,8e.6,8e.6,8c#6,a,8a,f#,a,a,g#,8e,8d.6,8d.6,8c#6,a,8a,f#,a,a,g#,8e,8e.6,8e.6,8c#6,a,8a,f#,a,a,g#,8d,8d.6,8d.6,8c#6";
//char *song = "Eiffel 65 - Blue : d=4,o=5,b=125:a,8a#,8d,8g,8a#,8c6,8f,8a,a#,8g,8a#,8d6,8d#6,8g,8d6,8c6,8a#,8d,8g,8a#,8c6,8f,8a,a#,8g,8a#,8d6,8d#6,8g,8d6,8c6,8a#,8d,8g,8a#,8a,8c,8f,g.,";
//char *song = "PinkPanther:d=4,o=5,b=160:8d#,8e,2p,8f#,8g,2p,8d#,8e,16p,8f#,8g,16p,8c6,8b,16p,8d#,8e,16p,8b,2a#,2p,16a,16g,16e,16d,2e";
//char *song = "ScoobyDoo:d=4,o=5,b=160:8e6,8e6,8d6,8d6,2c6,8d6,e6,2a,8a,b,g,e6,8d6,c6,8d6,2e6,p,8e6,8e6,8d6,8d6,2c6,8d6,f6,2a,8a,b,g,e6,8d6,2c6";
//char *song = "StarWars:d=4,o=5,b=180:8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6,p,8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6";
//char *song = "SuperMan:d=4,o=5,b=180:8g,8g,8g,c6,8c6,2g6,8p,8g6,8a.6,16g6,8f6,1g6,8p,8g,8g,8g,c6,8c6,2g6,8p,8g6,8a.6,16g6,8f6,8a6,2g.6,p,8c6,8c6,8c6,2b.6,g.6,8c6,8c6,8c6,2b.6,g.6,8c6,8c6,8c6,8b6,8a6,8b6,2c7,8c6,8c6,8c6,8c6,8c6,2c.6";
//char *song = "we-rock:d=4,o=6,b=40:32f#.5,32g.5,32a.5,32d6,32a.5,32d6,32a5,32d6,32a.5,16e.6,32a.5,16a5,8d.6,32g.5,32a.5,32b.5,32d6,32b.5,32d6,32b5,32d6,32b.5,16e.6,32a.5,16a5,8d.6,32f#.5,32g.5,32a.5,32d6,32a.5,32d6,32a5,32d6,32a.5,16e.6,32a.5,16a5,8d.6,32g.5,32a.5,32b.5,32d6,32b.5,32d6,32b5,32d6,32b.5,16e.6,32a.5,16a5,16d.6,";
//char *song = "mslug:d=4,o=5,b=63:32f,32c,32a#,32d#,8d#.6,32d6,32d#6,32d6,32c6,32a#,32d6,16c.6,32f,f.,32g#,32d#,32c#6,32f#,8f#.6,32f7,32f#6,32f6,32d#6,32c#6,32f6,16d#6,16d6,16d#6,g#6,16g#,16g#,16a#,8b.,32a#,32g#,8a#,8d#,8a.,32g#,32f#,8g#,8c#,8g#.,32f#,32e,8c#,8d#,8e,2d#";
char *song2 = "GunsAndR:d=4,o=6,b=225:d5,d,a5,g5,g,a5,f_,d5,d,a5,g5,g,a5,f_,a5,e5,d,a5,g,a5,f_,a5,e5,d,a5,g5,g,a5,f_,a5,f_,a5,e5,d,a5,g5,g,a5,f_,a5";
//char *song = "Jackassth:d=4,o=6,b=140:8e5,8f5,8g.5,16g5,8g5,p,8p,8e5,8f5,8g.5,16g5,8g5,p,16p,8f5,8e5,8d5,c5,p,8p,8f5,8e5,8d5,c5,2p,8e5,8f5,8g.5,16g5,8g5,p,8p,8e5,8f5,8g.5,16g5,8g5,p,16p,8f5,8e5,8d5,c5,p,8p,8f5,8e5,8d5,c5";
//char *song = "LinkinPar:d=4,o=6,b=125:d5,a5,a5,f5,e5,e5,e5,8f5,8e5,d5,a5,a5,f5,2e,p,a5,a5,e5,e5,e5,8f5,8e5,d5,a5,a5,f5,2e5";
//char *song = "LinkinPar:d=4,o=6,b=125:g_,8p,8g_,g_,8f_,8g_,g_,8g_,8g_,g_,b,f_,8p,8g_,g_,8f_,8g_,g_,8g_,8g_,g_,f_,g_,8g_,8g_,g_,f_,g_,8g_,8g_,g_,b,f_,8g_,8g_,g_,f_,g_,8g_,8g_,g_,f_,g_";
char *song3 = "gbusters:d=4,o=5,b=112:16b,16b,8d#6,8b,8c#6,8a,2p,16b,16b,16b,16b,8a,8b,2p,16b,16b,8d#6,8b,8c#6,8a,2p,16b,16b,16b,16b,8a,8c#6,8b";
char *song4 = "addams:d=4,o=5,b=160:8c,8d,8e,8f,1p,8d,8e,8f#,8g,1p,8d,8e,8f#,8g,p,8d,8e,8f#,8g,p,8c,8d,8e,8f,1p,8c,f,8a,f,8c,b4,g.,8f,e,8g,e,8c,a4,f.,8c,f,8a,f,8c,b4,g.,8f,e,8c,d,8e,2f";
//char *song = "spongebob:d=4,o=5,b=112:c7,a6,g6,e6,c7,a6,g6,e6,c7,a6,g6,e6,8g.6,16g6,2a6,b6,2c7,2p,c7,a6,g6,e6,c7,a6,g6,e6,c7,a6,g6,e6,8g.6,16g6,2a6,b6,2c7,2p,c7,a6,g6,e6,c7,a6,g6,e6,c7,a6,g6,e6,8g.6,16g6,2a6,b6,2c7,2p,c7,a6,g6,e6,c7,a6,g6,e6,c7,a6,g6,e6,8g.6,16g6,2a6,b6,2c7";
char *song5 = "HappyBirt:d=4,o=6,b=225:c5,c5,d5,c5,f5,e5,p,c5,c5,d5,c5,g5,f5,p,c5,c5,a5,g5,f5,e5,d5,p,a5,a5,g5,f5,g5,f5";
//char *song = "Piratesof:d=4,o=6,b=100:8a.5,8c.,8d.,8c,16a_5,8a5,16a5,8g5,16g5,f5,16p,16a5,16a.5,32p,16a5,16a5,16a5,16a5,16a5,16a5,16a5,16a5,16a5,16a5,16d.,32p,16a5,16f5,16f5,16g5,16a.5,p,16a5,16a_5,16a_5,16a_5,16g5,16g5,16g5,16a5,16a5,16a5,16f5,16f5,16f5,16g5,16g5,16g5,16g5,16a5";
//char *song = "007_best:d=4,o=6,b=200:16d_5,32f5,32f5,16d_5,16d_5,16d_5,32f_5,16f_5,8f_5,16f5,16f5,16f5,16d_5,32f5,32f5,16f5,8f5,16d_5,16d_5,16d_5,16d_5,32f_5,32f_5,16f_5,8f_5,16f5,16e5,16d_5,16d_,2d,16a_5,16g_5";
//char *song ="CrazyFrog:d=4,o=6,b=125:f5,8g_.5,16f5,16p,16f5,8a_5,8f5,8d_5,f5,8c.,16f5,16p,16f5,8c_,8c,8g_5,8f5,8c,8f,16f5,16d_5,16p,16d_5,8c5,8g5,f5,8p,p,2p,f5,8g_.5,16f5,16p,16f5,8a_5,8f5,8d_5,f5,8c.,16f5,16p,16f5,8c_,8c,8g_5,8f5,8c,8f,16f5,16d_5,16p,16d_5,8c5,8g5,f5,8p,p,2p,f5,8g_.5,16f5,16p,16f5,8a_5,8f5,8d_5,f5,8c.,16f5,16p,16f5,8c_,8c,8g_5,8f5,8c,8f,16f5,16d_5,16p,16d_5,8c5,8g5,f5";
//char *song = "SpiceGirl:d=4,o=6,b=125:16g5,16g5,16g5,16g5,8g5,8a5,8g5,8e5,8p,16c5,16d5,16c5,8d5,8d5,8c5,e5,p,8g5,8g5,8g5,8a5,8g5,8e5,8p,c,8c,8b5,8g5,8a5,16b5,16a5,g5";
char *song6 = "HarryPott:d=4,o=6,b=100:2p,8p,8b5,8e.,16g,8f_,e,8b,a.,f_.,8e.,16g,8f_,d,8f,2b5,8p,8b5,8e.,16g,8f_,e,8b,d7,8c_7,c7,8g_,8c.7,16b,8a_,f_,8g,b,8g,c7,8b,a_,8f_,8g.,16b,8a_,a_5,8b5,2b,8p";
//char *song = "WillSmith:d=4,o=6,b=160:a_5,g5,a_5,g5,p,8f5,8g5,8g5,8g5,2a_5,8a_5,8a_5,8a_5,8a_5,a_5,8a_5,8c,a_5,g5,g5,a_5,g5,a_5,g5,p,8f5,8g5,8g5,8g5,2a_5,8a_5,8a_5,8a_5,8a_5,a_5,8a_5,8c,a_5,g5,g5,a_5,g5,a_5,g5,p,8f5,8g5,8g5,8g5,2a_5,8a_5,8a_5,8a_5,8a_5,a_5,8a_5,8c,a_5,g5,g5,a_5,g5,a_5,g5,p,8f5,8g5,8g5,8g5,2a_5,8a_5,8a_5,8a_5,8a_5,a_5,8a_5,8c,a_5,g5,g5";
//char *song = "BobMarley:d=4,o=6,b=160:8c_5,e5,f_5,8p,2a5,8p,8f_5,8p,8c_5,e5,f_5,1p,a5,16p,a5,16p,a5,g_5,a5,g_5,f_5";
char *song7 = "RedHotCh:d=4,o=6,b=100:8e,8e,8e,8e,d,8e,d,2c.,p,8e,8e,8e,8e,d,8e,8d,2c.,16c,8c,8c,16c,16c,8b5,8c,8c,16c,16c,8b5,8c,8c,8c,8b5,a5,8a5,16c,16c,8c,8c,16c,16c,8b5,8c,8c,16c,16c,8b5,8c,8c,8e";
//char *song = "LedZeppel:d=4,o=6,b=80:8g,16p,8f_,16p,8f,16p,8e,16p,8d,8a5,8c,16p,8b5,16p,a_5,8a5,16f5,16e5,16d5,8p,16p,16a_5,16a_5,16a_5,8p,16p,16b5,16b5,16b5,8p,16p,16b5,16b5,16b5,8p,16p,16c,16c,16c,8p,16p,16c,16c,16c";
//char *song = "Nirvana:d=4,o=6,b=125:8a_5,8a5,a5,2g5,8c,8c,c,2a_5,8d_5,8d_5,d_5,d.5,8p,8c,8c,c,2a_5,8a_5,8a5,a5,g.5,8p,8c,8c,c,2a_5,8d_5,8d_5,d_5,d.5,8p,8c,8c,c,2a_5,a_.5";
//char *song = "GOT:d=32,o=4,b=320:2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4e5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4e5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,1g.6,p,1c.6,p,4d#6,p,4f6,p,1g6,p,1c6,p,4d#6,p,4f6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.6,p,1a#.5,p,4d6,p,4d#6,p,1f6,p,1a#5,p,4d#6,p,4d6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1g.6,p,1c.6,p,4d#6,p,4f6,p,1g6,p,1c6,p,4d#6,p,4f6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.6,p,1a#.5,p,4d6,p,4d#6,p,1f6,p,1a#5,p,4d#6,p,4d6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1g.7,p,1c.7,p,4d#7,p,4f7,p,1g7,p,1c7,p,4d#7,p,4f7,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.7,p,1a#.6,p,1d7,p,1d#7,p,1d7,p,1a#6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p";


void setup(void)
{
  Serial.begin(9600);
  tone1.begin(9);
}

#define isdigit(n) (n >= '0' && n <= '9')


void play_rtttl(char *p)
{
 
  // Absolutely no error checking in here

  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  // format: d=N,o=N,b=NNN:
  // find the start (skip name, etc)

  while(*p != ':') p++;    // ignore name
  p++;                     // skip ':'

  // get default duration
  if(*p == 'd')
  {
    p++; p++;              // skip "d="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    if(num > 0) default_dur = num;
    p++;                   // skip comma
  }

  Serial.print("ddur: "); Serial.println(default_dur, 10);

  // get default octave
  if(*p == 'o')
  {
    p++; p++;              // skip "o="
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;                   // skip comma
  }

  Serial.print("doct: "); Serial.println(default_oct, 10);

  // get BPM
  if(*p == 'b')
  {
    p++; p++;              // skip "b="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }

  Serial.print("bpm: "); Serial.println(bpm, 10);

  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

  Serial.print("wn: "); Serial.println(wholenote, 10);


  // now begin note loop
  while(*p)
  {
    // first, get note duration, if available
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

    // now get the note
    note = 0;

    switch(*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;

    // now, get optional '#' sharp
    if(*p == '#')
    {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }
  
    // now, get scale
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;       // skip comma for next note (or we may be at the end)

    // now play the note


    if(note)
    {
      Serial.print("Playing: ");
      Serial.print(scale, 10); Serial.print(' ');
      Serial.print(note, 10); Serial.print(" (");
      Serial.print(notes[(scale - 4) * 12 + note], 10);
      Serial.print(") ");
      Serial.println(duration, 10);
      tone1.play(notes[(scale - 4) * 12 + note]);
      delay(duration);
      tone1.stop();
    }
    else
    {
      Serial.print("Pausing: ");
      Serial.println(duration, 10);
      delay(duration);
    } 
  } 
}

void loop(void)
{
  // Primeiramente você vai no código da música e enumera as músicas que vc quer na sequência como song1, song2, song3 e etc...
  // Aqui você aumenta a sequência de músicas copiando e colando o código quantas vezes você quiser, só alterando o número da constante "song": 
  // Exemplo:
  // play_rtttl(song2);
  // Serial.println("Done.");
  // while(0);
  // delay(1000);
  
  play_rtttl(song1);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  play_rtttl(song2);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  play_rtttl(song3);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  play_rtttl(song4);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  play_rtttl(song5);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  play_rtttl(song6);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  play_rtttl(song7);
  Serial.println("Done.");
  while(0);
  delay(1000);
  
  /*play_rtttl(song8);
  Serial.println("Done.");
  while(0);
  delay(1000);*/
  
}



