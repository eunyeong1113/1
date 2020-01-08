/*
let a=22;
let b=a-5;
a=4;
console.log(b,a);

const a=22;//변수가 바뀔 수 없게 하는 명령어
let b=a-5;//변수가 바껴도 되는 명령어
a=4;
console.log(b,a);


//String
const what="Nicolas";
console.log(what);


//Boolean
const what = true;

//Number
//Float
const wat = 55.1;

const monday="Mon";
const tue="Tue";
const wed="Wed";
const thu="Thu";
const fri="Fri";

const something = "something"
const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun",54,true,something];
console.log(daysOfWeek);

const nicoInfo={
    name: "Nicol",
    age : 33,
    gender:"Male",
    isHansome : true
};
console.log(nicoInfo.gender);
nicoInfo.gender = "female";
console.log(nicoInfo.gender);
*/
const nicoInfo={
    name: "Nicol",
    age : 33,
    gender:"Male",
    isHansome : true,
    favMov:["a","b","c"],
    favFood:[
        {
            name:"A",
            fatty:false
        },
        {
            name:"B",
            fatty:true
        }
    ]
};
console.log(nicoInfo);
console.log(nicoInfo.favFood[0].fatty);