const weather=document.querySelector(".js-weather");

const API_KEY="f970ff3030c50ff24d34d4372743fe20";
const COORDS ='coords';

function getWeather(lat,lng)
{
    fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lng}&appid=${API_KEY}&units=metric`)
    .then(function(response){
        return response.json();
    })
    .then(function(json){
       const temperature=json.main.temp;
       const place=json.name;
       weather.innerText=`${temperature}@${place}`;
        // console.log(json);
    });
}

function saveCoords(coordsObj){

    localStorage.setItem(COORDS,JSON.stringify(coordsObj));
}

function handleGeoSucces(position)
{
    const latitude=position.coords.latitude;
    const longitude=position.coords.longitude;
    const coordsObj={

        latitude,
       longitude
       
        // latitude:latitude,
       // longitude:longitude
    };
    //console.log(position);
    saveCoords(coordsObj);
    getWeather(latitude,longitude);
}

function handleGeoError()
{
    console.log("Cant access geo location");

}

function askForCoords()
{
    navigator.geolocation.getCurrentPosition(handleGeoSucces,handleGeoError);
}

function loadCoords()
{
    const loadedCords=localStorage.getItem(COORDS);
    if(loadedCords===null)
    {
        askForCoords();
    }else{
        const parseCoords=JSON.parse(loadedCords);
        getWeather(parseCoords.latitude,parseCoords.longitude);
        //console.log(parseCoords);
    }
}


function init()
{
    loadCoords();
}
init();