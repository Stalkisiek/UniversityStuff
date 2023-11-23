// prompt. Co zrobić. 
// new -> dodaje element do listy i wyświetla go z podpiskiem "x dodany do listy"
// list -> wyświetla wszystko w liście w formule *********\n 0:x1 1:x2 *******
// delete -> na podstawie indexu
// quit -> kończy 
// jak jest błędne niech sprawdza

let input = prompt("What u wanna do?");
let arr = [];

while(input !== 'quit'){
    input = input.trim();
    if(input === 'new'){
        let text = prompt("What u want to add?");
        arr.push(text);
        console.log(`${text} has been added to index ${arr.length - 1}`);
    }
    else if(input === 'list'){
        console.log('*********');
        for(let i = 0; i < arr.length; i++){
            console.log(`${i}: ${arr[i]}`);
        }
        console.log('*********');
    }
    else if(input === 'delete'){
        let index = prompt('Write index of what u want delete!');
        if(index > arr.length - 1 || index < 0) { 
            console.log('Wrong index!')
        }
        else{
            arr.splice(index,1);
            console.log('New list looks like this:');
            console.log('*********');
            for(let i = 0; i < arr.length; i++){
                console.log(`${i}: ${arr[i]}`);
            }
            console.log('*********');
        }
    }
    else{
        console.log('Sorry. I dont understand :(');
    }
    input = prompt("What u wanna do now?");
}

do{
    console.log(123);        
}while(1 < 2);