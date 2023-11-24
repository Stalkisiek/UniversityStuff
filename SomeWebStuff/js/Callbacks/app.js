const numbers = [];

for(let i = 0; i < 100; i++){
    if(i % 2 == 0){
        numbers.push(i);
    }
}

let temp = numbers.filter((x) => {
    return x % 4 === 0;
})
