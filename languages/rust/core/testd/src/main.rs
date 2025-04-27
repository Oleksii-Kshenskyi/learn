use std::hint::unreachable_unchecked;
use std::time::Instant;

struct Type {
    inc: u64,
    val: u64,
}

struct Var {
    from: u64,
    to: u64,
}

#[inline(always)]
fn collatz_result(varr: &Var) {
    // Use u32 for the cache - the iterations will fit in u32
    let mut cache = vec![0u32; varr.to as usize];
    let mut at = Type { inc: 0, val: 0 };

    // Set known base case
    cache[1] = 0;

    for val in varr.from..varr.to {
        let mut val_local = val;
        let mut itr = 0u32;

        // Fast path for powers of 2
        if (val & (val - 1)) == 0 {
            cache[val as usize] = val.trailing_zeros() as u32;
            continue;
        }

        loop {
            // We're using a common optimization here
            if val_local < val && val_local > 0 {
                unsafe {
                    // Avoid bounds checking for known-valid indices
                    if *cache.get_unchecked(val_local as usize) != 0 {
                        itr += *cache.get_unchecked(val_local as usize);
                        break;
                    }
                }
            }

            match val_local {
                0 => unsafe { unreachable_unchecked() }, // This should never happen
                1 => break,
                _ => {
                    if val_local & 1 == 1 {
                        // Odd number: optimization for next two steps at once
                        // This avoids potential overflow by dividing first
                        val_local = ((val_local * 3) + 1) >> 1;
                        itr += 2;
                    } else {
                        // Even number
                        val_local >>= 1;
                        itr += 1;
                    }
                }
            }
        }

        unsafe {
            *cache.get_unchecked_mut(val as usize) = itr;
        }

        if itr > at.inc as u32 {
            at.inc = itr as u64;
            at.val = val;
        }
    }

    println!("num: {}", at.val);
    println!("inc: {}", at.inc);
}

fn main() {
    println!("Привіт, світ!");

    let vart = Var {
        from: 1,
        to: 99_999_999,
    };

    let start = Instant::now();
    collatz_result(&vart);
    let duration = start.elapsed();

    println!("Час виконання: {} мс", duration.as_millis());
    let i: i32 = 5;
    if i {
        println!("{}", i);
    }
}
