import './App.css';
import {ToDoList} from "./features/ToDoList/components/ToDoList";
import ToDoForm from "./features/ToDoList/components/ToDoForm";
import toDoForm from "./features/ToDoList/components/ToDoForm";
import {useState} from "react";
import {Todo} from "./features/ToDoList/types/todo";

function App() {
    const [todos, todoesSet] = useState<Todo[]>([]);

    const handleAt = (todo: Todo) => {
        const oldTodos = [...todos, todo];
        // oldTodos.push(todo);
        todoesSet(oldTodos);
    }
    return (
        <div className="App">
            <ToDoList todos={todos}/>
            <ToDoForm addElement={handleAt}/>
        </div>
    );
}

export default App;
