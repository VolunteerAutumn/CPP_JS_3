alert("Time test begins now.");

// --- TIME OBJECT ---
const Time = new Object();
Time.hours = 20;
Time.minutes = 30;
Time.seconds = 45;

// --- FUNCTION TO SHOW TIME ---
function showTime(obj) {
    // Pad with leading zeros for nice display
    let h = obj.hours.toString().padStart(2, '0');
    let m = obj.minutes.toString().padStart(2, '0');
    let s = obj.seconds.toString().padStart(2, '0');
    console.log(`${h}:${m}:${s}`);
}

// --- FUNCTION TO ADD SECONDS ---
function addSeconds(obj, sec) {
    obj.seconds += sec;
    while (obj.seconds >= 60) {
        obj.seconds -= 60;
        obj.minutes += 1;
    }
    while (obj.minutes >= 60) {
        obj.minutes -= 60;
        obj.hours += 1;
    }
    while (obj.hours >= 24) {
        obj.hours -= 24;
    }
}

// --- FUNCTION TO ADD MINUTES ---
function addMinutes(obj, min) {
    obj.minutes += min;
    while (obj.minutes >= 60) {
        obj.minutes -= 60;
        obj.hours += 1;
    }
    while (obj.hours >= 24) {
        obj.hours -= 24;
    }
}

// --- FUNCTION TO ADD HOURS ---
function addHours(obj, hr) {
    obj.hours += hr;
    while (obj.hours >= 24) {
        obj.hours -= 24;
    }
}

// --- TEST ---
showTime(Time);       // 20:30:45
addSeconds(Time, 30); 
showTime(Time);       // 20:31:15
addMinutes(Time, 90); 
showTime(Time);       // 22:01:15
addHours(Time, 5);    
showTime(Time);       // 03:01:15 (wraps past 24h)
