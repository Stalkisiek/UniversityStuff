function dice(howMany, sides){
    let value = 0;
    for(let i = 0; i < howMany; i++){
        value += Math.floor(Math.random() * sides) + 1;
    }

    return value;
}


function temp(x,y){
    return function(a){
        return x + y + a;
    }
}


const temp = {
    func(x,y){
        return x + y;
    }
}