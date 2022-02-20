if [[ -d release ]]; then 
    cd src && g++ -o candycrush.exe main.cpp -lallegro -lallegro_image -lallegro_ttf -lallegro_font && mv candycrush.exe  ../release && cp -r ../src/assets ../release
else
    mkdir release && cd src && g++ -o candycrush.exe main.cpp -lallegro -lallegro_image -lallegro_ttf -lallegro_font && mv candycrush.exe  ../release && cp -r ../src/assets ../release
fi

#Somente testado na estrutura de arquivos atual, e em apenas um ambiente de desenvolvimento específico