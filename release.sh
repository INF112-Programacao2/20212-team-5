cd src
if [[ -d assets ]]; then
    if [[ -d ../release ]]; then
        cp -r ../src/assets ../release
        if [[ -e CandyCrush.exe ]]; then
            mv ../src/CandyCrush.exe ../release
        fi
    else
        mkdir ../release && cp -r ../src/assets ../release
    fi
fi
