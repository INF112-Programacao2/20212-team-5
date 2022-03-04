if [[ -d release ]]; then 
    cd src && g++ -o candycrush.out main.cpp -lallegro -lallegro_image -lallegro_ttf -lallegro_font && mv candycrush.out  ../release && cp -r ../src/assets ../release
else
    mkdir release && cd src && g++ -o candycrush.out main.cpp -lallegro -lallegro_image -lallegro_ttf -lallegro_font && mv candycrush.out  ../release && cp -r ../src/assets ../release
fi