# Para demonstração do trabalho final, adicionar a flag -mwindows
cd src
if [[ -d assets ]]; then
    if [[ -d ../release ]]; then
        cp -r ../src/assets ../release
    else
        mkdir ../release && cp -r ../src/assets ../release
    fi
fi

#Somente testado na estrutura de arquivos atual, e em apenas um ambiente de desenvolvimento específico