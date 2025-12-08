# Libft

## Description
Le projet **Libft** consiste à recréer certaines fonctions standard de la librairie C (`libc`) ainsi que quelques fonctions supplémentaires pour manipuler des chaînes de caractères, des tableaux et la mémoire. Toutes les sources, headers et le Makefile sont dans le même dossier.

## Structure du projet
```bash
libft/
├── ft_strlen.c
├── ft_strcpy.c
├── ft_strdup.c
├── ft_atoi.c
├── ft_isalpha.c
├── ft_isdigit.c
├── ft_memset.c
├── ft_bzero.c
├── ft_memcpy.c
├── ft_memmove.c
├── ft_memchr.c
├── ft_memcmp.c
├── ft_strcmp.c
├── ft_strncmp.c
├── ft_toupper.c
├── ft_tolower.c
├── ft_strchr.c
├── ft_strrchr.c
├── ft_strcat.c
├── ft_strncat.c
├── ft_lstnew.c # bonus
├── ft_lstadd_front.c # bonus
├── ft_lstsize.c # bonus
├── libft.h
├── libft.a # généré par Makefile
└── Makefile
```
## Compilation
```bash
make        # compile la librairie
make clean  # supprime les fichiers objets
make fclean # supprime libft.a et fichiers objets
make re     # fclean + recompilation
```
## Fonctions disponibles

| Fonction     | Description courte                             |
| ------------ | ---------------------------------------------- |
| `ft_strlen`  | Renvoie la longueur d’une chaîne               |
| `ft_strcpy`  | Copie une chaîne dans une autre                |
| `ft_strncpy` | Copie n caractères d’une chaîne                |
| `ft_strdup`  | Duplique une chaîne                            |
| `ft_strcat`  | Concatène deux chaînes                         |
| `ft_strncat` | Concatène n caractères d’une chaîne            |
| `ft_strchr`  | Cherche un caractère dans une chaîne (premier) |
| `ft_strrchr` | Cherche un caractère dans une chaîne (dernier) |
| `ft_strcmp`  | Compare deux chaînes                           |
| `ft_strncmp` | Compare n caractères de deux chaînes           |
| `ft_atoi`    | Convertit une chaîne en entier                 |
| `ft_isalpha` | Vérifie si caractère alphabétique              |
| `ft_isdigit` | Vérifie si caractère numérique                 |
| `ft_isalnum` | Vérifie si alphanumérique                      |
| `ft_isascii` | Vérifie si caractère ASCII                     |
| `ft_isprint` | Vérifie si caractère imprimable                |
| `ft_toupper` | Convertit en majuscule                         |
| `ft_tolower` | Convertit en minuscule                         |
| `ft_memset`  | Remplit une zone mémoire avec un octet         |
| `ft_bzero`   | Met à zéro une zone mémoire                    |
| `ft_memcpy`  | Copie une zone mémoire                         |
| `ft_memmove` | Copie une zone mémoire en gérant chevauchement |
| `ft_memchr`  | Cherche un octet dans une zone mémoire         |
| `ft_memcmp`  | Compare deux zones mémoire                     |

## Bonus (listes chaînées)

| Fonction          | Description courte                              |
| ----------------- | ----------------------------------------------- |
| `ft_lstnew`       | Crée un nouvel élément                          |
| `ft_lstadd_front` | Ajoute un élément au début                      |
| `ft_lstsize`      | Renvoie le nombre d’éléments                    |
| `ft_lstlast`      | Renvoie le dernier élément                      |
| `ft_lstadd_back`  | Ajoute un élément à la fin                      |
| `ft_lstdelone`    | Supprime un élément                             |
| `ft_lstclear`     | Supprime toute la liste                         |
| `ft_lstiter`      | Applique une fonction à chaque élément          |
| `ft_lstmap`       | Crée une nouvelle liste avec fonction appliquée |

