# Script that download every rom in a list automaticaly and class them

# Create the temporary directory
#mkdir temp
#cd temp

FILESDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd ~/RetroPie/roms/
# Download each console seperatly with bios

echo "looking for ROMlist in $FILESDIR"

# Download GameBoyAdvance
mkdir -p gba
cd GameBoyAdvance
wget -i $FILESDIR/GameBoyAdvance.txt
#unzip \*.zip
cd  ..

# Download NES
mkdir -p nes
cd Nintendo
wget -i $FILESDIR/Nintendo.txt
#unzip \*.zip
cd ..

# Download N64
mkdir -p n64
cd Nintendo64
wget -i $FILESDIR/Nintendo64.txt
#unzip \*.zip
cd ..

# Download SegaGenesis
mkdir -p megadrive
cd SegaGenesis
wget -i $FILESDIR/SegaGenesis.txt
#unzip \*.zip
cd ..

# Download SuperNintendo
mkdir -p snes
cd SuperNintendo
wget -i $FILESDIR/SuperNintendo.txt
#unzip \*.zip
cd ..

echo "Gaming Time :D"
