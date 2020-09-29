<template>
    <div class="content">
        <div class="info-tables">
            <h1>Co oferujemy:</h1>
            <div class="line"></div>
            <div class="info">
                <div class="circle"></div>
                <h2>Lorem ipsum</h2>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque elementum dui quis nisl ullamcorper.</p>
            </div>
            <div class="info">
                <div class="circle"></div>
                <h2>Lorem ipsum</h2>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque elementum dui quis nisl ullamcorper.</p>
            </div>
            <div class="info">
                <div class="circle"></div>
                <h2>Lorem ipsum</h2>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque elementum dui quis nisl ullamcorper.</p>
            </div>
        </div>

        <div class="info-text">
            <h1>Lorem ipsum</h1>
            <p>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent laoreet posuere justo et placerat. Phasellus et diam nec diam maximus ullamcorper. Vestibulum semper tempus varius. Duis scelerisque tempus magna id mattis. Proin sit amet eleifend sem, eget dapibus felis. Proin volutpat ex in augue tristique, ut egestas eros faucibus. Curabitur quis tempor magna. Nullam venenatis sollicitudin massa, id lobortis lacus iaculis at. Maecenas vel justo commodo, fermentum mi in, pellentesque nisi. Aliquam erat volutpat. Integer mattis turpis vel pulvinar tincidunt. In a varius arcu.
            </p>
            <p>
                Quisque sed nibh at sapien auctor laoreet. Nam at diam gravida, luctus quam vel, porta ipsum. Etiam blandit erat et posuere suscipit. Quisque quam ante, scelerisque at aliquet id, faucibus vel eros. Morbi finibus ornare elit nec ornare. Pellentesque efficitur feugiat nunc, vitae accumsan risus semper at. Nulla tortor turpis, eleifend non lorem tempor, semper efficitur leo. Etiam leo mi, malesuada ut sem vel, mollis volutpat urna. Maecenas dapibus justo lectus, vitae consequat ex consequat a. Mauris commodo ligula in nisi ultricies volutpat. Vestibulum lobortis risus vel justo tempus dignissim. Nulla iaculis sapien sed lacinia sagittis. Sed tincidunt interdum ipsum, a finibus mauris bibendum id. Vestibulum id augue semper, rutrum lacus ut, scelerisque lacus.
            </p>

        </div>

        <div class="info-picture">
            <div class="text">
                <h1>Lorem ipsum</h1>
                <p>
                Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent laoreet posuere justo et placerat. 
                </p>
                <button>Go to</button>
            </div>
            <div class="picture"></div>

        </div>
    </div>
</template>



<style scoped>
.info-tables{
    padding: 50px 0;
    text-align:center;
}

.info-tables .line{
    margin: 0 auto;
    background: #839783;
    width: 50px;
    height: 3px;
}

.circle{
    display: inline-block;
    background:#839783;
    border-radius:50px;
    width:75px;
    height:75px;
}

.info-tables .info{
    border-radius: 10px;
    display: inline-block;
    margin: 60px 30px;
    padding: 20px 30px 0px 30px;
    height: 200px;
    width: 240px;
}

.info-tables .info h2{
    font-size:18px;
    color:#111111;
}
.info-tables .info p{
    font-size:16px;
}

.info-text{
    background:white;
    display:block;
    
}

.info-picture{
    display:flex;
}

.info-picture .text{
    width:30%;
}

.info-picture .text h1{
    font-size:36px;
}

.info-picture .text p{
    font-size:24px;
}

.info-picture .picture{
    background:black;
    width: 300px;
    height:300px;
    position:relative;
    display:flex;
    margin-left: 100px;
    
}
</style>