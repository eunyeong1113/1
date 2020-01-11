const todoForm=document.querySelector(".js-todoform"),
toDoInput =todoForm.querySelector("input"),
toDoList=document.querySelector(".js-toDoList");

const TODOS_LS="toDos";

const toDos=[];

function deleteToDo(event)
{
    
}

function saveToDos()
{
    localStorage.setItem(TODOS_LS,JSON.stringify(toDos));
}

function paintToDo(text)
{
    const li=document.createElement("li");
    const delBtn=document.createElement("button");
    const span=document.createElement("span");
    const newId=toDos.length+1;

    delBtn.innerText="X"
    span.innerText=text; 
    li.appendChild(delBtn);
    li.appendChild(span);
    li.id=newId;
    toDoList.appendChild(li);  

    const toDoObj={
        text:text,
        id: newId
    };

    toDos.push(toDoObj);  
    saveToDos();
    //console.log(text);
}

function handleSubmit(event)
{
    event.preventDefault();
    const currentValue=toDoInput.value;
    paintToDo(currentValue);
    toDoInput.value="";
}

function loadToDos()
{
    const loadedToDos=localStorage.getItem(TODOS_LS);
    if(loadedToDos!==null){
        const parsedToDos=JSON.parse(loadedToDos);
        parsedToDos.forEach(function(toDo){
            paintToDo(toDo.text);
            //console.log(toDo.text);
        });
        //console.log(parsedToDos);
        //console.log(loadedToDos);
    }
    else{

    }
}

function init()
{
    loadToDos();
    todoForm.addEventListener("submit",handleSubmit);
}
init();