// In this file we will looking at a simple program demonstrating working of timers in JavaScipt.

// We will be creating a clock timer for 2 minutes.

// setting time to 2 minutes
let time = 120; //Time is seconds.

// Creating executable function
const timerFunc = function(){
	const hour = String(Math.trunc(time/3600)).padStart(2,'0');
	const min = String(Math.trunc(time/60)).padStart(2,'0');
	const sec = String(Math.trunc(time%60)).padStart(2,'0');
	// Displaying the timer
	console.log(hour,":",min,":",sec);

	// Stopping the timer when it is 0 seconds.
	if(time==0){
		clearInterval(timer);
	}
	time--;
}
const timer = setInterval(timerFunc,1000); 
//Here I have set time to 1000 milliseconds as I want it to repeat it after every 1 second.
