alert("Test begins now.");

const Car = new Object();
Car.company = "Mitsubishi";
Car.model = "Outlander";
Car.year = 2025;
Car.avgspeed = 120;

function showinfo(obj) {
    console.log(obj);
}

function travelTime(car, distance) {
    let t = distance / car.avgspeed;
    let breaks = Math.floor(t / 4);
    let totalTime = t + breaks;
    return totalTime;
}

showinfo(Car);
console.log(`Time calculation: ${travelTime(Car, 120).toFixed(2)} hours`);
