#!/bin/bash

# Chemin de l'exécutable à adapter si besoin
CUB3D_EXEC=./cub3D

# Options valgrind (utilisées si --valgrind est passé)
USE_VALGRIND=false
VALGRIND_CMD="valgrind --leak-check=full --show-leak-kinds=all"

# Vérifie si l'option --valgrind est activée
if [[ "$1" == "--valgrind" ]]; then
    USE_VALGRIND=true
fi

maps=(
    map/inv01_no_extension
    map/inv02_wrong_extension.cubic
    map/inv03_empty.cub
    map/inv04_new_lines.cub
    map/inv05_wrong_caract.cub
    map/inv06_no_start.cub
    map/inv07_two_same_start.cub
    map/inv08_two_diff_start.cub
    map/inv09_unclosed_map.cub
    map/inv10_unclosed_map2.cub
    map/inv11_unclosed_map3.cub
    map/inv12_miss_texture.cub
    map/inv13_miss_color.cub
    map/inv14_mixed_texture_map.cub
    map/inv15_no_map.cub
    map/inv16_map_space.cub
    map/inv17_incomplete_texture.cub
    map/inv18_incomplete_color.cub
    map/inv19_invalid_color1.cub
    map/inv20_no_texture_permission.cub
    map/inv21_unclosed_map4.cub
    map/inv22_double_texture.cub
    map/inv23_double_color.cub
    map/inv24_invalid_color2.cub
    map/inv25_invalid_color3.cub
    map/inv26_invalid_color4.cub
    map/inv27_invalid_color5.cub
    map/inv28_invalid_texture_path.cub
    map/inv29_invalid_texture_type.cub
)

# Vérifie si l'exécutable existe
if [ ! -x "$CUB3D_EXEC" ]; then
    echo "❌ Erreur : exécutable '$CUB3D_EXEC' introuvable ou non exécutable."
    exit 1
fi

# Lancement des tests
for map in "${maps[@]}"; do
    echo -e "\n===== Test de $map ====="
    
    if [ ! -f "$map" ]; then
        echo "❌ Fichier introuvable : $map"
        continue
    fi

    if $USE_VALGRIND; then
        $VALGRIND_CMD "$CUB3D_EXEC" "$map"
    else
        "$CUB3D_EXEC" "$map"
    fi
done
