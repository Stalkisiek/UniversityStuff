import {FC} from "react";
import {Todo} from "../types/todo";

interface ToDoListProps{
    todos: Todo[];
};

export const ToDoList: FC<ToDoListProps> = ({todos}) => {

    return(
        <>
            <ul>
                {todos.map((todo) => <li>todo</li>)}
            </ul>
        </>
    );
};