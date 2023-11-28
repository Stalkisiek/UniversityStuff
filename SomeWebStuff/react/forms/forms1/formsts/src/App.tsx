import './App.css';
import {ToDoList} from "./features/ToDoList/components/ToDoList";

function App() {
    return (
        <div className="App">
            <ToDoList todos={[{id: "abv", title: "123", isDone: false},{id: "abv", title: "123", isDone: false}]}/>
        </div>
    );
}

export default App;
