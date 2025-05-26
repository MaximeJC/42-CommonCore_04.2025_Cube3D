# cub3D - Projet 42

Ce projet est une implémentation d'un moteur de rendu 3D en raycasting, réalisé dans le cadre du cursus de l'École 42. Il permet d'afficher un environnement 3D à partir d'une carte 2D et de se déplacer à l'intérieur de cet environnement. Le thème global du projet est un **musée**.

## Compilation et Exécution

### Prérequis

* **MinilibX :** Il est impératif de compiler la MinilibX avant de compiler ce projet.

### Compilation

1.  **Cloner le dépôt :**

    ```bash
    git clone git@github.com:MaximeJC/42-Cursus_04.2025_Cube3D.git cub3D
    cd cub3D
    ```

2.  **Compiler la MinilibX :**

    ```bash
    make mlx
    ```

    * Cela compilera la MinilibX. Assurez-vous d'avoir les dépendances nécessaires (`libX11`, `libXext`) installées sur votre système.

3.  **Compiler le projet cub3D :**

    ```bash
    make
    ```

    * Cela compilera tous les fichiers sources et créera l'exécutable `cub3D`.

### Exécution

1.  **Lancer l'exécutable :**

    ```bash
    ./cub3D map/nom_de_ta_carte.cub
    ```

    * Remplacez `map/nom_de_ta_carte.cub` par le chemin vers un fichier de carte valide. Les fichiers de carte doivent avoir l'extension `.cub` et doivent être placés dans le dossier `map/`.

### Testeur de cartes

Un script de test (`test_map.sh`) est fourni pour vérifier la validité des fichiers de carte. Pour l'utiliser :

1.  **Rendre le script exécutable (si nécessaire) :**

    ```bash
    chmod +x test_map.sh
    ```

2.  **Retirer les permissions du fichier de texture `no_perm.xpm` :**

    ```bash
    chmod -r textures/no_perm.xpm
    ```

    * Ceci est nécessaire pour tester correctement les erreurs de permission de texture.

3.  **Exécuter le script :**

    ```bash
    ./test_map.sh
    ```

    * Le script testera plusieurs fichiers de carte invalides et affichera les résultats.
    * Vous pouvez également utiliser l'option `--valgrind` pour vérifier les fuites de mémoire pendant les tests :

        ```bash
        ./test_map.sh --valgrind
        ```

### Contrôles

* **Déplacement :**
    * `W` : Avancer
    * `A` : Se déplacer à gauche
    * `S` : Reculer
    * `D` : Se déplacer à droite
* **Rotation :**
    * Flèches gauche/droite OU Mouvement de la souris
* **Quitter :**
    * `ECHAP` ou Cliquer sur la croix de la fenêtre

### Structure du projet

* `cub3D/`
    * `Makefile`          : Fichier de compilation
    * `README.md`         : Ce fichier
    * `include/`          : Fichiers d'en-tête (.h)
        * `cub3d.h`
    * `libft/`            : Librairie personnelle (ft_printf, get_next_line, etc.)
        * `...`
    * `minilibx-linux/`   : MinilibX
        * `...`
    * `map/`              : Répertoire contenant les fichiers de carte (.cub)
        * `...`
    * `obj/`              : Répertoire pour les fichiers objets (.o) (généré)
    * `src/`              : Fichiers sources (.c)
        * `game_engine/`    : Logique du jeu (raycasting, mouvement, etc.)
            * `cam_mouvement.c`
            * `display.c`
            * `game_controls.c`
            * `mlx_management.c`
            * `player_movement.c`
            * `raycasting.c`
            * `...`
        * `parsing/`        : Analyse et validation des fichiers de carte
            * `check_mapfile.c`
            * `get_data_map.c`
            * `get_map.c`
            * `...`
        * `struct/`         : Définitions des structures de données
            * `struct_data.c`
            * `struct_img.c`
            * `struct_map.c`
            * `...`
        * `utils/`          : Fonctions utilitaires diverses
            * `error_handler.c`
            * `...`
    * `cub3D`               : Exécutable (généré)
    * `test_map.sh`         : Script de test pour les cartes invalides
    * `textures/`           : Répertoire contenant les textures
        * `no_perm.xpm`

### Remarques

* Ce projet a été développé dans le cadre du cursus de l'École 42.
* Le thème global de l'application est un **musée**.
* Assurez-vous de respecter les spécifications du sujet en termes de format de la carte, de textures, etc.
* En cas de problème, référez-vous au sujet du projet et aux ressources fournies par l'École 42.
