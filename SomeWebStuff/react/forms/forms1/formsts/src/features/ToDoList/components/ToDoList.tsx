import {FC} from "react";
import {Todo} from "../types/todo";
import '../Styles/listElements.css'
import ToDoListItem from "./ToDoListElement";

interface ToDoListProps{
    todos: Todo[];
}

export const ToDoList: FC<ToDoListProps> = (props: ToDoListProps) => {
    const todos = props.todos;
    return(
        <>
            <ul className="list-group">
                {todos.map((t : Todo) => <ToDoListItem key={t.id} todo={t}/>)}
            </ul>
        </>
    );
};