#!/bin/bash

# Chemin vers l'exécutable Cub3D
CUB3D_EXEC=./cub3D

# Liste des maps à tester (v00 exclue)
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
    map/inv19_incorrect_color.cub
    map/inv20_no_texture_permission.cub
    map/inv21_unclosed_map4.cub
)

echo "===== DÉBUT DES TESTS ====="

for map in "${maps[@]}"; do
    echo -e "\n===================================="
    echo "🗺️  Test de la map : $map"

    if [ ! -f "$map" ]; then
        echo "❌ Fichier introuvable"
        continue
    fi

    # Lancement de Cub3D, affiche stdout + stderr (notamment messages d’erreur visibles)
    $CUB3D_EXEC "$map"
    status=$?

    echo -e "➡️  Code de retour : $status"
done

echo -e "\n===== FIN DES TESTS ====="
