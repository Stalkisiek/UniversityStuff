import {FC, useState} from "react";
import {Todo} from "../types/todo";

interface ToDoListItemProps{
    todo: Todo;
}

const ToDoListItem: FC<ToDoListItemProps> = ({todo}) => {
    const [listElementType, listElementTypeChange] = useState("");
    const onClickLsItem = (e : React.MouseEvent) => {
        if(!listElementType){
            listElementTypeChange("lsclicked");
        }
        else{
            listElementTypeChange("");
        }
    }
    return <li className={listElementType} key={todo.id} onClick={ (e) => onClickLsItem(e)}>{todo.title}</li>;
}

export default ToDoListItem;