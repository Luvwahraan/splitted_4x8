
# Clavier BÉPO orthogonal en deux parties.

Cette keymap a été pensée pour la disposition BÉPO (http://bepo.fr), qui est une disposition de clavier francophone, ergonomique et libre, élaborée selon la méthode Dvorak.

L’adaptation de cette disposition à l’Ergodone (probablement utilisable avec l’Ergodox) a été réalisée en essayant de profiter de l’ergonomie du clavier pour conserver l’alternance des mains propre au BÉPO.

La couche de base suit le BÉPO, avec les touches « ç » et « W » déplacées pour coller à la disposition ortholinéaire.

Un certains nombre de fonctionnalités du firmware QMK sont utilisées dans cette keymap. Elles sont expliquées dans la section ***Particularités*** et détaillées dans la section ***Fonctions***.


## Particularités

### Modificateurs

Les modificateurs et touches spéciales sont placés vers les extérieurs, en fonctions secondaires sur des touches. SHIFT, GUI et ALT étant sur les lignes du bas, et CTRL sur les côtés.
Ils sont activables en gardant les touches appuyées.


### LEAD

La touche *LEAD*, une autre fonctionnalité apportée par QMK, est également employée pour accéder à des macros ou des codes spéciaux. Pour en activer une, il est nécessaire de taper la touche LEAD, puis un ordre spécifique de codes sur n’importe quelle couche.

Par exemple ici `LEAD`→`L`→`O`→`L` passe le layer **LOCK** en seul actif (ce qui ne laisse que la possibilité d’enlever ce layer via la même fonction).


### Bureaux virtuels

Des fonctions rapides ont été ajoutées pour naviguer dans les bureaux virtuels de X.org (ce sont des appuis simultanés sur `LCTRL`, `ALT` et une flèche) :
* `L_D` : vers l’espace de travail de gauche
* `R_D` : vers l’espace de travail de droit
* `U_D` : vers l’espace de travail du haut
* `D_D` : vers l’espace de travail du bas.


### Tap Dance

La fonctionnalité Mod Tap du firmware QMK permet d’avoir plusieurs fonctions sur une seule touche.
Cette fonctionnalité permet de gérer finement les répétitions de touches.

Les raccourcis de `F1` à `F10` sont accessibles en tapant plusieurs fois les touches `"` à `)` sur la première ligne. Par exemple `(`→`(`→`(` ferme la fenêtre en cours, en envoyant la séquence `ALT+F4`.

La plupart des modificateurs sont activables grâce à cette fonctionnalité.


### Fonctions

Comme dans la version originale, une couche est utilisée pour les touches de fonctions (`F1-12` et plus). C’est sur cette couche qu’on peut gérer les couches, avec les pouces.

Une deuxième couche fonction qui ne remplace que la première ligne est disponible et bloquable (couche **FLOK**).


### Macros

Deux macros fonctionnants ensembles sont utilisées avec cette keymap : la première permet de changer le set de calques, et la deuxième de naviguer dans les sets de base.
Elles sont utilisables via les pouces sur la couche **FNCT**, elle-même activable en maintenant une des touches espace.

## Fonctions

### Mod Tap/Hold Tap

Pressée         | Tapée
----------------|----------
`⎈ gauche`      | `Tab`
`🡅 gauche`      | `⎄`
`❖`             | `à`
`⌥`             | `y`
`⎇`             | `F`
`≣`             | `W`
`🡅 droit`       | `⎄`
`⎈ droit`       | `Mute`


### Tap dance

Les touches Tap Dance peuvent être tapées relachées, ou tapées et relachées plusieurs fois et maintenues.

#### Tapées

Touche    | tap1     | Hold     | tap2     | tap3     | tap4    | 
----------|----------|----------|----------|----------|---------|
 `"`      | `"`      |          | `F1`     | `⌥+F1`   | `⎈+F1`  |
 `«`      | `«`      |          | `F2`     | `⌥+F2`   | `⎈+F2`  |
 `»`      | `»`      |          | `F3`     | `⌥+F3`   | `⎈+F3`  |
 `(`      | `(`      |          | `F4`     | `⌥+F4`   | `⎈+F4`  |
 `)`      | `)`      |          | `F5`     | `⌥+F5`   | `⌥+F5`  |
 `@`      | `@`      |          | `F6`     | `⌥+F6`   | `⌥+F6`  |
 `+`      | `+`      |          | `F7`     | `⌥+F7`   | `⌥+F7`  |
 `-`      | `-`      |          | `F8`     | `⌥+F8`   | `⌥+F8`  |
 `/`      | `/`      |          | `F9`     | `⌥+F9`   | `⌥+F9`  |
 `*`      | `*`      |          | `F10`    | `⌥+F10`  | `⌥+F10` |
 `⎄`      | `⎄`      | `🡅`      | `⎄⎄`     |          |         |
 `⎌`      | `⎌`      |          | `😊`      |          |         |
 `🕪`      | `🕪`      | `⎈`      |          |          |         |
 `ESPACE` | `ESPACE` |          |`Workspace`|          |         |




# Crédits

> [Luvwahraan](https://github.com/Luvwahraan) <Luvwahraan+ErgoBepo@Pikaed.Org>

