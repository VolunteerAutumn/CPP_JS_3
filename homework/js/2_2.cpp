alert("Test begins now.");

const Io1 = new Object()
const Io2 = new Object()
Io1.num = 1
Io2.num = 2
Io1.den = 3
Io2.den = 4

function GCD(a, b) {
    while (b != 0) {
        let temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

function LCM(a, b) {
    return (a * b) / GCD(a, b);
}

function simplify(fraction) {
    let gcd = GCD(fraction.num, fraction.den);
    return { num: fraction.num / gcd, den: fraction.den / gcd };
}

// ADDITION
function addFractions(f1, f2) {
    let commonDen = (f1.den * f2.den) / GCD(f1.den, f2.den);
    let num1 = f1.num * (commonDen / f1.den);
    let num2 = f2.num * (commonDen / f2.den);
    return simplify({ num: num1 + num2, den: commonDen });
}

// SUBTRACTION
function subtractFractions(f1, f2) {
    let commonDen = (f1.den * f2.den) / GCD(f1.den, f2.den);
    let num1 = f1.num * (commonDen / f1.den);
    let num2 = f2.num * (commonDen / f2.den);
    return simplify({ num: num1 - num2, den: commonDen });
}

// MULTIPLICATION
function multiplyFractions(f1, f2) {
    return simplify({ num: f1.num * f2.num, den: f1.den * f2.den });
}

// DIVISION
function divideFractions(f1, f2) {
    return simplify({ num: f1.num * f2.den, den: f1.den * f2.num });
}



console.log("Add:", addFractions(Io1, Io2));       // 5/6
console.log("Subtract:", subtractFractions(Io1,Io2)); // -1/6
console.log("Multiply:", multiplyFractions(Io1,Io2)); // 1/6
console.log("Divide:", divideFractions(Io1,Io2));     // 2/3
