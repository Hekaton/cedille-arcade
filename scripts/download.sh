# Script that download every rom in a list automaticaly and class them

# Create the temporary directory
mkdir temp
cd temp

# Download each console seperatly with bios

# Download GameBoyAdvance
mkdir GameBoyAdvance
cd GameBoyAdvance
wget -i ../../GameBoyAdvance.txt
unzip \*.zip
cd  ..

# Download NES
mkdir Nintendo
cd Nintendo
wget -i ../../Nintendo.txt
unzip \*.zip
cd ..

# Download N64
mkdir Nintendo64
cd Nintendo64
wget -i ../../Nintendo64.txt
unzip \*.zip
cd ..

# Download SegaGenesis
mkdir SegaGenesis
cd SegaGenesis
wget -i ../../SegaGenesis.txt
unzip \*.zip
cd ..

# Download SuperNintendo
mkdir SuperNintendo
cd SuperNintendo
wget -i ../../SuperNintendo.txt
unzip \*.zip
cd ..

echo "Gaming Time :D"
