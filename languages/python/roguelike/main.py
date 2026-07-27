import tcod

WORLD_WIDTH = 60
WORLD_HEIGHT = 36
ROOM_WIDTH = 30
ROOM_HEIGHT = 20

def print_room(console: tcod.console.Console):
    center_x = int(WORLD_WIDTH / 2)
    center_y = int(WORLD_HEIGHT / 2)

    room_x = int(center_x - (ROOM_WIDTH / 2))
    room_y = int(center_y - (ROOM_HEIGHT / 2))

    console.print(x=room_x, y=room_y, text=('─' * ROOM_WIDTH))
    for i_y in range(room_y, room_y + ROOM_HEIGHT):
        console.print(x=room_x, y=i_y, text='█')
    console.print(x=room_x, y=(room_y + ROOM_HEIGHT - 1), text=('─' * ROOM_WIDTH))
    for i_y in range(room_y, room_y + ROOM_HEIGHT):
        console.print(x=(room_x + ROOM_WIDTH - 1), y=i_y, text='█')

def main():
    tileset = tcod.tileset.load_truetype_font(
        "fonts/JuliaMono-Regular.ttf",
        tile_width=12,
        tile_height=20,
    )
    console = tcod.console.Console(WORLD_WIDTH, WORLD_HEIGHT)
    with tcod.context.new(
        console=console,
        tileset=tileset,
        title="Roguelike Prototype",
        vsync=True,
    ) as context:
        while True:
            console.clear()
            print_room(console)
            context.present(console)
            for event in tcod.event.wait():
                match event:
                    case tcod.event.Quit():
                        raise SystemExit
                    case tcod.event.KeyDown(sym=tcod.event.KeySym.ESCAPE):
                        raise SystemExit


if __name__ == "__main__":
    main()
