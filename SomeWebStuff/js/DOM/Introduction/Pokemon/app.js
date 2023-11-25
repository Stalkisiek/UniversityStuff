// https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png
const cont = document.querySelector('#container');
const link = 'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/'

for(let i = 1; i < 151; i++){
    const divHolder = document.createElement('div');
    divHolder.classList = 'pokemon';
    const img = document.createElement('img');
    img.src = `${link}${i}.png`;
    const text = document.createElement('span');
    text.innerText = i;
    divHolder.appendChild(img);
    divHolder.appendChild(text);
    //img.classList.add('pokemon');
    cont.appendChild(divHolder);
}
