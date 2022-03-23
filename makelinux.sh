# Para demonstração do trabalho final, adicionar a flag -mwindows
if [[ -d release ]]; then 
    cd src && g++ main.cpp -lallegro -lallegro_image -lallegro_ttf -lallegro_font -o candycrush.out   && mv candycrush.out  ../release && cp -r ../src/assets ../release
else
    mkdir release && cd src && g++ main.cpp -lallegro -lallegro_image -lallegro_ttf -lallegro_font -o candycrush.out && mv candycrush.out  ../release && cp -r ../src/assets ../release
fi

#Somente testado na estrutura de arquivos atual, e em apenas um ambiente de desenvolvimento específico
