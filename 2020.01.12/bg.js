const body=document.querySelector("body");

const IMG_NUMBER=3;
/*
function handleImgLoad()
{
    console.log("finished loading");
}*/

function paintImage(imgNumber)
{
    const image= new Image();
    image.src=`/images/${imgNumber+1}.jpg`;
    image.classList.add("bgImage");
    body.prepend(image);
    //image.addEventListener("loadend",handleImgLoad);
    //body.appendChild(image);
}

function geRandom()
{
    const number= Math.floor(Math.random()*IMG_NUMBER);
    return number;
}

function init()
{
    const randomNumber=geRandom();
    paintImage(randomNumber);
}

init();