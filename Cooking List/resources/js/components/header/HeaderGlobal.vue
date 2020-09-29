<template>
    <header>
        <Navigation></Navigation>

        <h1>{{siteName}}</h1>

    </header>
</template>

<script>
import Navigation from './Navigation';

export default {
    props:['siteName'],
    components:{
        Navigation
    }

}
</script>

<style scoped>
    header{
        width: 100%;
        height: 30vh;
        background: linear-gradient( rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.55) ),url("../../assets/img/background.jpg");
        background-repeat: no-repeat;
        background-size: cover;
        box-shadow: inset 0 0 5px 2px #282a2d;
    }

    h1{
        text-align:center;
        font-size:40px;
        color:#fff;  
    }

</style>