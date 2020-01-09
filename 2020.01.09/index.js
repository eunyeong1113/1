/*

//2-6
const title=document.querySelector("#title");

const BASE_COLOR = "#000000";
const OTHER_COLOR= "rgb(0,0,255)";

function handleClick()
{
    const currentColor = title.style.color;

    if(currentColor===BASE_COLOR)
    {
        console.log(title.style.color);
        title.style.color = "rgb(0,0,255)";
    }
    else
    {
        title.style.color=BASE_COLOR;
    }
    
    console.log(BASE_COLOR);
    console.log(currentColor);
   
}

function init()
{
    title.style.color=BASE_COLOR;
    title.addEventListener("click",handleClick);
    console.log(title.style.color);
}
init();

//HTML JavaScript DOM event MDN
function handleOffline()
{
    console.log("bye");
}
function handleOnline()
{
    console.log("Hi");
}
window.addEventListener("online",handleOnline);
window.addEventListener("offline",handleOffline);
*/

//2.7
const title=document.querySelector("#title");

const CLICKED_CLASS="clicked";

function handleClick()
{
    const currentClass = title.className;
    //console.log(currentClass);
    if(currentClass!==CLICKED_CLASS)
    {
        title.className=CLICKED_CLASS;
    }
    else{
        title.className="";
    }
} 

function init()
{
    title.addEventListener("click",handleClick);
}
init();