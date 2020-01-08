/*
//2.1
const nicoInfo={
    name: "Nicol",
    age : 33,
    gender:"Male",
    isHansome : true,
};
console.log(nicoInfo,console);

function sayHello(name,age)
{
    console.log('Hello!',name,"you have",age,"years of age");
}
sayHello("Nicolas",15);

//2.1.1
function sayHello(name,age)
{
   // console.log(`Hello ${name} you are ${age} years old`);
   return `Hello ${name} you are ${age} years old`;
}

const greetNicolas=sayHello("Nicolas",15);
console.log(greetNicolas);

const calculator={
    plus: function(a,b)
    {
        return a+b; 
    }

}
//console.log(greetNicolas);
//const plus=calculator.plus(5,5)
console.log(calculator.plus(5,5));


//2-2,2-3
//const title=document.getElementById("title");
const title=document.querySelector("#title");
title.innerHTML="Hi! From JS";
title.style.color="red";
document.title="I own you now";
//console.dir(title);
//console.log(title);
//console.error("Fuck");


function handleResize()
{
    console.log("I have been resized");
}


//2-4
const title=document.querySelector("#title");

function handleResize()
{
    console.log("I have been resized");
}

window.addEventListener("resize",handleResize);

const title=document.querySelector("#title");

function handleResize(event)
{
    console.log(event);
}

window.addEventListener("resize",handleResize);

const title=document.querySelector("#title");

function handleClick()
{
    title.style.color="blue";
}

window.addEventListener("click",handleClick);

//2-5
if("10"===10)
{
    console.log("Hi");
}
else
{
    console.log("Ho");
}

if("10"===10)
{
    console.log("Hi");
}
else if("10"==="10")
{
    console.log("lalala");
}
else
{
    console.log("Ho");
}
if(20>5&&"nicolas"==="nicolas")
{
    console.log("yes");
}
else{
    console.log("no");
}
if(20>5||"niolas"==="nicolas")
{
    console.log("yes");
}
else{
    console.log("no");
}
const age=prompt("How old are you");
//console.log(age);
if (age>=18 && age<=21)
{
    console.log("you can drink but should not");
}
else if(age>21)
{
    console.log("go ahead");
}
else{
    console.log("too young");
}*/

//2-6