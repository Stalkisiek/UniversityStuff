import {FC, FormEvent, useRef} from "react";
import '../Styles/formStyleSheet.css'
import {Todo} from "../types/todo";

interface ToDoFormProps{
    addElement: (todo:Todo) => void;
}

export const ToDoForm: FC<ToDoFormProps> = ({addElement}) => {

    const titleRef = useRef<HTMLInputElement>(null);
    const handleSubmit = (e : FormEvent<HTMLFormElement>) => {
        e.preventDefault();

        const title = titleRef.current?.value ?? '';
        const todo: Todo = {title: title, id:title, isDone: false};
        addElement(todo);
    }
    return(
        <>
            <form onSubmit={(e) => handleSubmit(e)}>
                <input ref={titleRef} type="text" name="" id="" required={true}/>
                <button type="submit">Send data!</button>
            </form>
        </>
    );
};

export default ToDoForm;