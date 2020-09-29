<template>
    <div class="content">
        <div>
            <div class="add-ingredient">
                <input 
                    v-model="newIngredient.product" 
                    v-on:keyup.enter="addIngredient" 
                    type="text" 
                    name="addIngredient"
                    placeholder="Add an ingredient and then click enter"
                />
            </div>
            <div class="list-ingredient">
                <div v-for="ingredient in ingredients" v-bind:key="ingredient.id" class="ingredient" >
                    <input type="checkbox" v-model="ingredient.done" v-on:click="updateIngredient(ingredient,ingredient.product,!ingredient.done)">
                    <span>
                    {{ingredient.product}}
                    </span>
                    <i v-on:click="delIngredient(ingredient)" class="fas fa-times-circle"></i>
                </div>
            </div>        
        </div>
    </div>
</template>

<script>
export default {
    data(){
        return {
            newIngredient:{done:false,product:''},
            ingredients:{}
        }
    },
    methods:{
        getIngredient(){
            axios.get('api/ingredient').then(response=>{
                this.ingredients=response.data;
            });
        },
        addIngredient(){
            if(this.newIngredient!=''){
                this.ingredients.push(this.newIngredient);
                axios.post('api/ingredient',this.newIngredient).then(response=>{
                    this.getIngredient();
                    console.log(response);
                }).catch(error=>{
                    console.log(error);
                });
                this.newIngredient={done:false,product:''};
            }
        },
        updateIngredient(ingredient,product,done){
            ingredient.product=product;
            ingredient.done=done;
            
            axios.post('api/ingredient/update',ingredient).then(response=>{
                this.getIngredient();
                console.log(response);
            }).catch(error=>{
                console.log(error);
            })
        },
        
        delIngredient(ingredient){
            axios.post('api/ingredient/delete',ingredient).then(response=>{
                this.getIngredient();
                console.log(response);
            }).catch(error=>{
                console.log(error);
            });
        }
    },
    created(){
        this.getIngredient();
    }
}
</script>

<style scoped>
    .list-ingredient{
        border:1px solid #acacac;
        border-bottom:0px;
        box-shadow: 2px 2px 13px 0px #525252;
    }

    .ingredient{
        border-bottom:1px solid #acacac;
        padding: 20px 30px 20px 30px;
        background: white;
        font-size:20px;
    }

    .ingredient span{
        margin:20px;
    }

    .ingredient i{
        color:#c72525;
        float:right;
    }

    .add-ingredient{
        box-shadow: 2px 2px 13px 0px #525252;
        padding: 20px 30px 20px 30px;
        margin-bottom: 20px;
        background: white;
    }
    .add-ingredient input{
        padding: 10px;
        font-size: 18px;
        border: 1px solid grey;
        display: block;
        margin:auto;
        width: 90%;
        background: #f1f1f1;
    }
</style>