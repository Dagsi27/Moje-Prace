<template>
    <header>
        <Navigation></Navigation>
        <div class="item">
            <div class="info">
                <h1>Lorem Ipsum</h1>
                <p>
                Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam pretium semper consectetur. 
                </p>
            </div>
            <span><button>Let's Start!</button></span>
            

        </div>

    </header>
</template>

<script>
import Navigation from './Navigation';

export default {
    components:{
        Navigation
    }

}
</script>

<style scoped>
    header{
        width: 100%;
        height: 70vh;
        background: linear-gradient( rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.55) ),url("../../assets/img/background.jpg");
        background-repeat: no-repeat;
        background-size: cover;
        box-shadow: inset 0 0 5px 2px #282a2d;
    }

    .item{
    text-align:center;
    width: 500px;
    height: 250px;
    margin: 100px auto;
    padding: 20px;
    text-shadow: 0px 0px 7px #000;
    }

    .item .info h1{
        font-size:40px;
        color:#fff;
        
    }

    .item .info p{
        font-size:30px;
    
        color:#e7e7e7;
    }
</style>