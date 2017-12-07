function setData(startVal, stopVal, stepVal) {
    var floatStart = parseFloat(startVal);
    var floatStop = parseFloat(stopVal);
    var floatStep = parseFloat(stepVal);

    var nElements = parseInt(Math.abs((floatStop - floatStart) / floatStep)) + 1;

    var strStep = stepVal.toString();
    var dataPrecision = strStep.length - strStep.indexOf(".") - 1;
    var dataDiviedr = Math.pow(10, dataPrecision);

    var tempData = new Array(nElements);

    for (var i = 0; i < nElements; i++) {
        tempData[i] = Math.round((floatStart + i * floatStep) * dataDiviedr) / dataDiviedr;
    }

    return tempData;
}
