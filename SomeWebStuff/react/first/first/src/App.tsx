import Message from "./Message";
import ListGroup from "./Components/ListGroup";
import React from "react";

function onSelectItem(str:string) : void {
    console.log(str);
}

function App() {
    let arr = ["One", "Two", "Six"];
    const arr2 = ["Cat1", "Cat2", "Cat3"];
    return <div><ListGroup items={arr} heading={"Numbers"} onSelectItem={(str : string) => {console.log(str)}}/>
        <ListGroup items={arr2} heading={"Cats"} onSelectItem={onSelectItem}></ListGroup>
    </div>;
}

export default App;