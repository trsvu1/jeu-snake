# 🐍 Snike - Jeu du Serpent en Terminal

Bienvenue sur **Snike**, une version classique du jeu Snake développée en **C** et jouable directement depuis votre terminal !  
Cette version intègre des mécaniques de jeu amusantes ainsi que des fonctionnalités comme un mode automatique, des vitesses ajustables, et la possibilité de sauvegarder la partie.

---

## 🚀 Fonctionnalités

- 🎮 Mécaniques classiques du jeu Snake
- 🍎 Mangez 3 pommes pour grandir
- 🧱 Détection de collisions (murs et auto-collision)
- 💾 Fonctionnalité de sauvegarde/chargement (prévue)
- 🧠 Mode de jeu automatique avec deux vitesses
- 🖥️ Fonctionne sur terminaux macOS et Linux

---

## 📦 Structure des fichiers

- `main.c` – Boucle principale du jeu
- `snike.c` – Logique du jeu (dessin, déplacement, collisions)
- `snike.h` – Fichier d'en-tête avec les structures de données et déclarations de fonctions

---

## ⚙️ Installation et Compilation

### ✅ Prérequis

- Un compilateur C comme `gcc`
- Fonctionne sous terminal macOS ou Linux (utilise `termios` et `unistd`)

### 🧪 Compiler le projet

```bash
gcc main.c snike.c -o snike
```

### ▶️ Lancer le jeu

```bash
./snike
```

---

## 🎮 Contrôles

Utilisez les touches suivantes pour jouer :

- `W` – Haut
- `S` – Bas
- `A` – Gauche
- `D` – Droite

Appuyez sur ces touches pendant la partie pour changer la direction du serpent.

---

## 🛠️ Méthodes utilisées

- `termios.h` et `fcntl.h` pour la gestion du clavier sans appuyer sur Entrée
- `usleep()` de `unistd.h` pour la temporisation
- Affichage avec `printf` et codes ANSI d’échappement
- Utilisation d’enums pour les directions et les modes de jeu

---

## 💡 Améliorations futures

- ✅ Mode automatique (lent/rapide)
- ✅ `getch()` et `kbhit()` compatibles Unix
- ⏳ Sauvegarde et chargement de partie via fichiers
- 🔊 Ajout de sons optionnels (bip)
- 🎨 Meilleure interface/expérience utilisateur en terminal

---

## 🧠 Auteur & Licence

Créé par **trsvu1**, passionné de jeux classiques.  
Libre d'utilisation, de modification et d'apprentissage.

Licence : MIT

---

Amusez-vous bien avec **Snike** et améliorez votre programmation en C ! 🐍
