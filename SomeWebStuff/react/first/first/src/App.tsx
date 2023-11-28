import React, {useState} from "react";
import './Components/temp.css'
import {NumberSpan} from "./Components/NumberSpan";
import {GetRandomButton} from "./Components/GetRandomButton";

function App() {
    const [number, setNumber] = useState(0);

    //setInterval(onRandomClick, 10000);

    return (
        <div>
            <NumberSpan number={number}/>
            <GetRandomButton onClick={(v) => setNumber(v)}>Generise number!</GetRandomButton>
        </div>
    );
}
export default App;