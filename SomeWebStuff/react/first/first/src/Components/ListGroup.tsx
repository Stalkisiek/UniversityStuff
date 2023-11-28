import {useState} from "react";
import './temp.css';

interface Data{
    items: string[];
    heading: string;
    onSelectItem: (arg:string) => void;
}

function ListGroup({items, heading, onSelectItem}: Data){
    // let selectedIndex = -1;
    const [selectedIndex, setSelectedIndex] = useState(-1);
    return <>
        <h1>List of {heading}</h1>
        <ul className="list-group">
            {items.map((item,index) => {
                return <li key ={item}
                           className={selectedIndex === index ? "list-group-item active" : "list-group-item"}
                           onClick={ () => {setSelectedIndex(index); onSelectItem(`${index} clicked of list ${heading}`)}}>
                    {item}</li>
            }
            )}
        </ul>
    </>
}

export default ListGroup;