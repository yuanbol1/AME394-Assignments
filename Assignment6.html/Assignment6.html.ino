<html>
<head>
<script src='asyncReq.js'></script>
<script>
function getData()
{
  var ts = new Date(document.getElementById("theTime").value).getTime()
  var url = "./getAverage?ts=" + ts;
  console.log(url);
  var callback = function(data){
    var ob = JSON.parse(data);
    console.log(data)
    var markup = "<h1> Temperature </h1>" + ob.t + "<h1>Humidity</h1>" + ob.h + "<h2> at " + new Date(ob.ts) + "</h2>";
    document.getElementById("data").innerHTML = markup;
  }
  loadFile(url, callback);
}

 function getAverage() {
var startTime = new Date(new Date(new Date().getTime()-24*60*60*1000).setHours(0,0,0,0));
var endTime = new Date(new Date(new Date().getTime()-24*60*60*1000).setHours(23,59,59,999))
  var from = startTime-endTime;
  var to = endTime;
    var tempSum = 0;
    var humSum = 0;
    for(var i=0; i< result.length; i++){
      tempSum += result[i].t || 0;
      humSum += result[i].t || 0;
    }
    var tAvg = tempSum/result.length;
    var hAvg = humSum/result.length;
    res.send(tAvg + " "+  hAvg);
  });
});

    function getValue(id){
        var t = typeof id == "object"?id:$("#"+id),val = t.val();
        if(!isNaN(val)&&val!=""){
            num+=1;
            val = Number(val);
        }else{val=0;t.val("")};
        return val;
    }
    avgId = typeof avgId =="object"?avgId:$("#"+avgId);
    num == 0 ? avgId.text("") : avgId.text((sum/num).toFixed(2));
}

var myArr = ["test1","test2","test3","test4"];
$("#par").on("change",".err",function(){
    handler(myArr,$("#test5"));
})
</script>
<style>
  input{
    font-size: 30px;
    font-family: Courier;
  }
</style>
</head>

<body>
  <h1> Daily Average</h1>
  <input onchange='getData()' type="date" id="theTime">
  <div id='data'>Choose a date</div>
</body>
</html>
