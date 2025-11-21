alert("Test begins now.");

const rectangle = new Object();
rectangle.p1 = {x: 2, y: 2};
rectangle.p2 = {x: 8, y: 6};
rectangle.p3 = {x: 8, y: 2};
rectangle.p4 = {x: 6, y: 6};

function ReturnInfo(obj) {
    console.log(obj);
}

function ReturnWidth(rectobj) {
    return rectobj.p3.x - rectobj.p1.x;
}

function ReturnHeight(rectobj) {
    return rectobj.p2.y - rectobj.p3.y;
}

function FindArea(rectobj) {
    let width = ReturnWidth(rectobj);
    let height = ReturnHeight(rectobj);
    return width * height;
}

function Perimeter(rectobj) {
    let width = ReturnWidth(rectobj);
    let height = ReturnHeight(rectobj);
    return 2 * (width + height);
}

// --- RESIZE FUNCTIONS ---
function ChangeWidth(rectobj, dw) {
    rectobj.p2.x += dw;
    rectobj.p3.x += dw;
}

function ChangeHeight(rectobj, dh) {
    rectobj.p2.y += dh;
    rectobj.p4.y += dh;
}

function ChangeSize(rectobj, dw, dh) {
    ChangeWidth(rectobj, dw);
    ChangeHeight(rectobj, dh);
}

// --- MOVE FUNCTIONS ---
function MoveX(rectobj, dx) {
    rectobj.p1.x += dx;
    rectobj.p2.x += dx;
    rectobj.p3.x += dx;
    rectobj.p4.x += dx;
}

function MoveY(rectobj, dy) {
    rectobj.p1.y += dy;
    rectobj.p2.y += dy;
    rectobj.p3.y += dy;
    rectobj.p4.y += dy;
}

function Move(rectobj, dx, dy) {
    MoveX(rectobj, dx);
    MoveY(rectobj, dy);
}

// --- TEST ---
ReturnInfo(rectangle);
console.log(`width: ${ReturnWidth(rectangle)}`);
console.log(`height: ${ReturnHeight(rectangle)}`);
console.log(`area: ${FindArea(rectangle)}`);
console.log(`perimeter: ${Perimeter(rectangle)}`);

console.log("\n--- Resize + Move Test ---");
ChangeSize(rectangle, 2, 1);
Move(rectangle, 3, 2);
ReturnInfo(rectangle);
console.log(`width: ${ReturnWidth(rectangle)}`);
console.log(`height: ${ReturnHeight(rectangle)}`);
console.log(`area: ${FindArea(rectangle)}`);
console.log(`perimeter: ${Perimeter(rectangle)}`);
