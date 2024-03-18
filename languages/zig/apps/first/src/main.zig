const std = @import("std");

const KEKW = enum {
    One,
    Two,
    Three,
};

pub fn fib(n: u64) u64 {
    if ((n == 0) or (n == 1)) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

pub fn main() !void {
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    std.debug.print("All your {s} are belong to us.\n", .{"codebase"});

    // stdout is for the actual output of your application, for example if you
    // are implementing gzip, then only the compressed bytes should be sent to
    // stdout, not any debugging messages.
    const stdout_file = std.io.getStdOut().writer();
    var bw = std.io.bufferedWriter(stdout_file);
    const stdout = bw.writer();

    try stdout.print("Run `zig build test` to run the tests.\n", .{});

    try bw.flush(); // don't forget to flush!

    var num: u8 = 42;
    std.debug.print("So this is a test message with a u8: {}, {}\n", .{ num, num + 1 });

    var arr = [_]u8{ 1, 2, 3, 4, 5 };
    arr[4] = 3;
    std.debug.print("Array apparently: {any}\n", .{arr});

    for (arr) |e| {
        std.debug.print("KEKW: {}\n", .{e});
    }

    std.debug.print("Fib {} is {}.\n", .{ 3, fib(3) });

    var nu: u32 = 69;
    var ptr = &nu;
    std.debug.print("Pointer: {}, value: {}.\n", .{ ptr, ptr.* });
    std.debug.print("Numerical systems?, {} {} {} {}\n", .{ 0b100000, 0o40, 32, 0x20 });

    var b: bool = false;
    while (!b) {
        std.debug.print("Once!\n", .{});
        b = true;
    }

    var et: KEKW = KEKW.Three;
    std.debug.print("Printed enum variant: {}\n", .{et});
    switch (et) {
        KEKW.One => {
            std.debug.print("ONE", .{});
        },
        KEKW.Two => {
            std.debug.print("TWO", .{});
        },
        KEKW.Three => {
            std.debug.print("THREE", .{});
        },
    }
}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
