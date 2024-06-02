# cube3d
cub3d es un juego de tipo raycasting en 3D inspirado en Wolfenstein 3D. Este proyecto está desarrollado en C utilizando la biblioteca gráfica MiniLibX. El objetivo es explorar un laberinto y sobrevivir a los enemigos.


https://github.com/AgustinaHeredia/cube3d/assets/119814051/603556b7-6bdd-47f4-95d0-b486afe930c3


## Características
Raycasting: Generación de gráficos 3D a partir de un mapa 2D.
MiniMapa: Visualización en tiempo real del mapa 2D.
Interacción: Movimiento del jugador.
Soporte de múltiples texturas: Paredes con diferentes texturas.

## Requisitos
GNU Make
gcc
MiniLibX
macOS (para soporte de MiniLibX, ya que utiliza frameworks específicos de macOS)
## Instalación
Clona el repositorio e instala las dependencias necesarias:

```bash
git clone https://github.com/tu_usuario/cub3d.git
cd cub3d
```
## Compilación
Compila el proyecto usando make:

```bash
make
```
Para compilar el bonus:

```bash
make bonus
```
## Ejecución
Después de compilar, puedes ejecutar el juego con:

```bash
./cub3d path/to/map.cub
```
Para ejecutar la versión bonus:

```bash
./cub3d_bonus path/to/map_bonus.cub
```
## Controles
W: Mover hacia adelante
A: Mover a la izquierda
S: Mover hacia atrás
D: Mover a la derecha
←: Rotar a la izquierda
→: Rotar a la derecha
ESC: Salir del juego

## Archivos de Mapa
El formato de archivo de mapa debe ser un archivo .cub. Ejemplo de un archivo de mapa:

```bash
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,0

111111111111111111111
100000000011000000001
101100000111000000001
100100000000000000001
111111111011000001111
100000000011000000001
101100000111000000001
100100000000000000001
111111111111111111111
```
## Desarrollo
Funciones Clave
Raycasting: Implementado en raycast.c
Renderizado: Manejo de gráficos en paint_map2d.c
Interacción: Gestión de eventos de teclado en key_press.c
MiniMapa: Renderizado del minimapa en draw_map_2d.c

## Contribuciones
Las contribuciones son bienvenidas. Si deseas contribuir, por favor sigue los siguientes pasos:

Haz un fork del proyecto.
Crea una nueva rama (git checkout -b feature/nueva-funcionalidad).
Realiza los cambios necesarios y haz commit (git commit -m 'Añadir nueva funcionalidad').
Empuja los cambios a tu rama (git push origin feature/nueva-funcionalidad).
Abre una Pull Request.

## Colaboradores

Este proyecto ha sido desarrollado conjuntamente:

- [Patricia Quintana Barcelona](https://github.com/pquintanabcn) 
- [Agustina Heredia Marengo](https://github.com/AgustinaHeredia)  

El proyecto es parte del curriculum de 42 Barcelona.


## Contacto
Para preguntas o soporte, puedes contactarme en agus.developer42@gmail.com
