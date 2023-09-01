import React, {useState} from 'react';
import logo from './logo.svg';
import './App.css';
import {NumberSpan} from "./NumberSpan";
import {GetRandomButton} from "./GetRandomButton";

function App() {
    const [number, setNumber] = useState(0);
    
  return (
    <div className="App">
      <NumberSpan number={number}/>
        <GetRandomButton onRandom={setNumber} max={100}/>
    </div>
  );
}

export default App;
