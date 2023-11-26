const score = document.querySelector('#score');
const rounds = document.querySelector('#rounds');
const button1 = document.querySelector('#b1');
const button2 = document.querySelector('#b2');
const reset = document.querySelector('#b3');
const all = document.querySelector('body');
let nrRounds = rounds.value;

let player1score = 0;
let player2score = 0;

function createScore(x,y){
    return `${x} to ${y}`;
}

function changeScore(){
    score.textContent = createScore(player1score,player2score);
}

function add1(){
    player1score++;
}

function add2(){
    player2score++;
}

function resetFunc(){
    button1.addEventListener('click', add1)
    button2.addEventListener('click', add2)
}


function turnOff(){
    button1.removeEventListener('click', add1)
    button2.removeEventListener('click', add2)
}

all.addEventListener('click', () => {
    changeScore();
    if(player1score == nrRounds){
        turnOff();
        
    }
})

reset.addEventListener('click', () =>{
    resetFunc();
})
