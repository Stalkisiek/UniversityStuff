let h1 = document.querySelector('h1');
let input = document.querySelector('input');

input.addEventListener('input', (e) => {
   h1.innerText = `Welcome, ${input.value}`;
});