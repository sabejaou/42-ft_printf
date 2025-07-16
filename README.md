# ft_printf

ft_printf est une ré-implémentation de la fonction printf standard du C, réalisée dans le cadre du cursus 42. Elle permet d'afficher des chaînes formatées avec gestion de plusieurs types d'arguments, tout en respectant les contraintes du projet 42.

## Sommaire
- [Fonctionnalités](#fonctionnalités)
- [Arborescence](#arborescence)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Liste des fonctions](#liste-des-fonctions)
- [Auteur](#auteur)

---

## Fonctionnalités
- Affichage formaté sur la sortie standard (stdout)
- Gestion des types :
  - `%c` : caractère
  - `%s` : chaîne de caractères
  - `%p` : pointeur (adresse mémoire)
  - `%d` / `%i` : entier signé
  - `%u` : entier non signé
  - `%x` / `%X` : hexadécimal (minuscule/majuscule)
  - `%%` : pourcentage
- Gestion des cas particuliers (`NULL`, `(nil)`, etc.)

---

## Arborescence

```
42-ft_printf/
├── includes/
│   └── ft_printf.h
├── src/
│   ├── core/
│   │   └── ft_printf.c
│   ├── format/
│   │   ├── ft_putadd_fd.c
│   │   └── ft_putadd_ul_fd.c
│   └── utils/
│       ├── ft_putnbr_fd.c
│       ├── ft_putnbr_ul_fd.c
│       └── ft_putstr_fd.c
├── obj/
├── Makefile
└── README.md
```

---

## Installation

1. **Cloner le dépôt**  
   ```sh
   git clone https://github.com/sabejaou/42-ft_printf.git
   cd 42-ft_printf
   ```

2. **Compiler la bibliothèque**  
   ```sh
   make
   ```
   Cela génère `libftprintf.a` à la racine du projet.

---

## Utilisation

1. **Inclure le header dans votre projet :**
   ```c
   #include "ft_printf.h"
   ```

2. **Compiler avec la bibliothèque :**
   - Ajoutez le chemin du header et de la lib à vos flags :
     ```sh
     gcc -I/path/to/42-ft_printf/includes -L/path/to/42-ft_printf -lftprintf votre_fichier.c
     ```
   - Exemple :
     ```sh
     gcc -I./includes -L. -lftprintf main.c
     ```

---

## Liste des fonctions

- `int ft_printf(const char *fmt, ...);`  
  Fonction principale, gère tous les formats ci-dessus.
- `void ft_putnbr_ul_fd(unsigned int nb, int fd, unsigned int *ct);`
- `void ft_putchar(char c, int fd, unsigned int *ct);`
- `void ft_putnbr_fd(int nb, int fd, unsigned int *ct);`
- `void ft_putadd_fd(unsigned int nb, unsigned long fd, const char *hex, unsigned int *ct);`
- `void ft_putstr_fd(char *s, int fd, unsigned int *ct);`
- `void ft_putadd_ul_fd(unsigned long nb, unsigned long fd, const char *hex, unsigned int *ct);`

---

## Auteur

- **Sabejaou**  
  [sabejaou@student.42lyon.fr](mailto:sabejaou@student.42lyon.fr)