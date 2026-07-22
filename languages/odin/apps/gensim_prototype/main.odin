package main

import "core:fmt"
import rl "vendor:raylib"

Position :: struct {
    x, y: int
}

Direction :: enum {
    Left,
    Right
}

Cell :: struct {
    pos: Position,
    direction: Direction,
}

turn_cell :: proc(c: ^Cell) {
    switch(c.direction) {
        case .Left:
            c.direction = .Right
        case .Right:
            c.direction = .Left
    }
}

main :: proc() {
    // fmt.println("Trying to initialize 5 cells...")
    // cells := make([dynamic] Cell)
    // defer delete(cells)

    // for i in 0..<5 {
    //     append(&cells, Cell {
    //         pos = { x = i, y = i},
    //         direction = .Right,
    //     })
    //     if i % 2 == 0 {
    //         turn_cell(&cells[i])
    //     }

    //     fmt.println("Cell ", i, ": ", cells[i])
    // }

    rl.InitWindow(800, 600, "Odin Sim")
    defer rl.CloseWindow()

    rl.SetTargetFPS(60)

    for !rl.WindowShouldClose() {
        rl.BeginDrawing()

        rl.ClearBackground(rl.DARKGRAY)
        rl.DrawText("RAYLIB!!", 20, 20, 30, rl.RED)
        rl.DrawRectangle(100, 100, 50, 50, rl.GREEN)

        rl.EndDrawing()
    }
}